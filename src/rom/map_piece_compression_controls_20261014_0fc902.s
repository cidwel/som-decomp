.setcpu "65816"
.segment "CODE"
.org $C902
map_control_0fc902:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
