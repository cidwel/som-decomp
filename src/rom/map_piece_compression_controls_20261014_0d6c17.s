.setcpu "65816"
.segment "CODE"
.org $6C17
map_control_0d6c17:
    .byte $E1 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
