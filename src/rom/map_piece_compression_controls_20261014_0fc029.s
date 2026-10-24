.setcpu "65816"
.segment "CODE"
.org $C029
map_control_0fc029:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
