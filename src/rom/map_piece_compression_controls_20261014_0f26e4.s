.setcpu "65816"
.segment "CODE"
.org $26E4
map_control_0f26e4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
