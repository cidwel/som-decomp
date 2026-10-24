.setcpu "65816"
.segment "CODE"
.org $7669
map_control_0f7669:
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
