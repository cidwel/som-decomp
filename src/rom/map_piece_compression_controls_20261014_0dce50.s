.setcpu "65816"
.segment "CODE"
.org $CE50
map_control_0dce50:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
