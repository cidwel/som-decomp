.setcpu "65816"
.segment "CODE"
.org $AE23
map_control_0fae23:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
