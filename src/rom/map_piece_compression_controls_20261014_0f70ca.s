.setcpu "65816"
.segment "CODE"
.org $70CA
map_control_0f70ca:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
