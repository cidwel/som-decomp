.setcpu "65816"
.segment "CODE"
.org $0F6A
map_control_0c0f6a:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
