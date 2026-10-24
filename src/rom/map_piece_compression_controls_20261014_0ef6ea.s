.setcpu "65816"
.segment "CODE"
.org $F6EA
map_control_0ef6ea:
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
