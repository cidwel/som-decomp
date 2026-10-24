.setcpu "65816"
.segment "CODE"
.org $BE49
map_control_0fbe49:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
