.setcpu "65816"
.segment "CODE"
.org $758F
map_control_0f758f:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
