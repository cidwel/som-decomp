.setcpu "65816"
.segment "CODE"
.org $942B
map_control_0f942b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
