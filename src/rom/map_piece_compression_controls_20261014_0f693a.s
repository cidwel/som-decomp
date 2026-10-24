.setcpu "65816"
.segment "CODE"
.org $693A
map_control_0f693a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
