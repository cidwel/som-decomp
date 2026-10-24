.setcpu "65816"
.segment "CODE"
.org $47CB
map_control_0d47cb:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
