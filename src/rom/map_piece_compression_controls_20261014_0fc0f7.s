.setcpu "65816"
.segment "CODE"
.org $C0F7
map_control_0fc0f7:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
