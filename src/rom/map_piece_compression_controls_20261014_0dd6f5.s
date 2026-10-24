.setcpu "65816"
.segment "CODE"
.org $D6F5
map_control_0dd6f5:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
