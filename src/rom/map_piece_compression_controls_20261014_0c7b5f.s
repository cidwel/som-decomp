.setcpu "65816"
.segment "CODE"
.org $7B5F
map_control_0c7b5f:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
