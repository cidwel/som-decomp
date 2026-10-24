.setcpu "65816"
.segment "CODE"
.org $DA7B
map_control_0fda7b:
    .byte $CD ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
