.setcpu "65816"
.segment "CODE"
.org $740B
map_control_0e740b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
