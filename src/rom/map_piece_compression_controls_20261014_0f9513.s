.setcpu "65816"
.segment "CODE"
.org $9513
map_control_0f9513:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
