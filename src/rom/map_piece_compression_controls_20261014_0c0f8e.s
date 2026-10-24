.setcpu "65816"
.segment "CODE"
.org $0F8E
map_control_0c0f8e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
