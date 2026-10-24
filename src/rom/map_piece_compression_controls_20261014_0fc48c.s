.setcpu "65816"
.segment "CODE"
.org $C48C
map_control_0fc48c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
