.setcpu "65816"
.segment "CODE"
.org $B63A
map_control_0fb63a:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
