.setcpu "65816"
.segment "CODE"
.org $6EC2
map_control_0c6ec2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
