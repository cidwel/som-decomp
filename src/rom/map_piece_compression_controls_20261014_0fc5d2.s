.setcpu "65816"
.segment "CODE"
.org $C5D2
map_control_0fc5d2:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
