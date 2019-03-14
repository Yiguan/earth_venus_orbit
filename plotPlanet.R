#install.packages("berryFunctions")
library(berryFunctions)
args = commandArgs(TRUE)

aa <- read.table(args[1], header = F, sep = "\t")
#aa <- read.table("gap10.txt",header = F, sep = "\t")

plot(NA, xlim = c(-1.5,1.5), ylim = c(-1.5,1.5), bty = "n", axes = F, ylab = "", xlab = "")
circle(0,0,1)
circle(0,0,0.7)
for (i in 1:nrow(aa)) {
	segments(aa[i,'V1'],aa[i,'V2'],aa[i,'V3'],aa[i,'V4'], col = rgb(0.9,0.2,0.2,0.2))
}

