.setcpu "65816"
.segment "CODE"
.org $11E0
map_control_0d11e0:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
