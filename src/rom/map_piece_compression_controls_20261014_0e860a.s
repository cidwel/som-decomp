.setcpu "65816"
.segment "CODE"
.org $860A
map_control_0e860a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
