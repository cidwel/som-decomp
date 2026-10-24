.setcpu "65816"
.segment "CODE"
.org $740E
map_control_0c740e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
