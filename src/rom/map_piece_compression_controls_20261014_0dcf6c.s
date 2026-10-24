.setcpu "65816"
.segment "CODE"
.org $CF6C
map_control_0dcf6c:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
