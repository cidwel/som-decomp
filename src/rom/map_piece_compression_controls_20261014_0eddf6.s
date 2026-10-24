.setcpu "65816"
.segment "CODE"
.org $DDF6
map_control_0eddf6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
