.setcpu "65816"
.segment "CODE"
.org $4CB0
map_control_0f4cb0:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
