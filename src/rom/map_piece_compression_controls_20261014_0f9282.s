.setcpu "65816"
.segment "CODE"
.org $9282
map_control_0f9282:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
