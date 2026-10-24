.setcpu "65816"
.segment "CODE"
.org $16CA
map_control_0f16ca:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
