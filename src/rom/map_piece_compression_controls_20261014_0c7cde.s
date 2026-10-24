.setcpu "65816"
.segment "CODE"
.org $7CDE
map_control_0c7cde:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
