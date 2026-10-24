.setcpu "65816"
.segment "CODE"
.org $133F
map_control_0f133f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
