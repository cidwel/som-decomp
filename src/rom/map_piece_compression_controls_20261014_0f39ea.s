.setcpu "65816"
.segment "CODE"
.org $39EA
map_control_0f39ea:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
