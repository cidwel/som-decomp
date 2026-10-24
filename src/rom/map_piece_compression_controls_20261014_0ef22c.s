.setcpu "65816"
.segment "CODE"
.org $F22C
map_control_0ef22c:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
