.setcpu "65816"
.segment "CODE"
.org $4271
map_control_0f4271:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
