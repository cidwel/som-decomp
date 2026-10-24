.setcpu "65816"
.segment "CODE"
.org $175B
map_control_0e175b:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
