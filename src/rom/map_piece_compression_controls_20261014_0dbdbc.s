.setcpu "65816"
.segment "CODE"
.org $BDBC
map_control_0dbdbc:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
