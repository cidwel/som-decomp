.setcpu "65816"
.segment "CODE"
.org $344E
map_control_0e344e:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
