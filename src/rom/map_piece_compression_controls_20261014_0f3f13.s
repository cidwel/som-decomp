.setcpu "65816"
.segment "CODE"
.org $3F13
map_control_0f3f13:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
