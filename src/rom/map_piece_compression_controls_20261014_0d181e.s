.setcpu "65816"
.segment "CODE"
.org $181E
map_control_0d181e:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
