.setcpu "65816"
.segment "CODE"
.org $C208
map_control_0fc208:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
