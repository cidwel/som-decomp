.setcpu "65816"
.segment "CODE"
.org $7DC5
map_control_0f7dc5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E4 ; previous-row copy count
