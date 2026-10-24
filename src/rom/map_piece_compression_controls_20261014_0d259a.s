.setcpu "65816"
.segment "CODE"
.org $259A
map_control_0d259a:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
