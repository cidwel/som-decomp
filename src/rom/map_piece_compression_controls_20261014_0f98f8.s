.setcpu "65816"
.segment "CODE"
.org $98F8
map_control_0f98f8:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
