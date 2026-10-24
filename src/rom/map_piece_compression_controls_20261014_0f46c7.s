.setcpu "65816"
.segment "CODE"
.org $46C7
map_control_0f46c7:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
