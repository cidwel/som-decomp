.setcpu "65816"
.segment "CODE"
.org $CE9A
map_control_0dce9a:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
