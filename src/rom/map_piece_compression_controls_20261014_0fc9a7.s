.setcpu "65816"
.segment "CODE"
.org $C9A7
map_control_0fc9a7:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
