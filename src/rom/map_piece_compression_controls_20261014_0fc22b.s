.setcpu "65816"
.segment "CODE"
.org $C22B
map_control_0fc22b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
