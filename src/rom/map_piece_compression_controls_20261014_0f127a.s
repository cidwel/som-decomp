.setcpu "65816"
.segment "CODE"
.org $127A
map_control_0f127a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
