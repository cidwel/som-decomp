.setcpu "65816"
.segment "CODE"
.org $D0CC
map_control_0ed0cc:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
