.setcpu "65816"
.segment "CODE"
.org $B39A
map_control_0fb39a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
