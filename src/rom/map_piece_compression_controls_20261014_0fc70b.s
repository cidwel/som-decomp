.setcpu "65816"
.segment "CODE"
.org $C70B
map_control_0fc70b:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
