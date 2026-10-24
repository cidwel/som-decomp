.setcpu "65816"
.segment "CODE"
.org $96A5
map_control_0f96a5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
